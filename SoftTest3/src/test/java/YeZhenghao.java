import extractbot.tool.BaseExtractor;

import java.io.*;
import java.util.*;

public class YeZhenghao extends BaseExtractor{

	/** TODO
	 *	YeZhenghao: Change the path of "cfgparser_path" to your local path.
	 */
	private static String cfgparser_path = "C:\\Users\\YztHowe\\Desktop\\Code\\Code\\SoftTest3\\src\\test\\java\\cfgparser.jar";
	private List<List<String>> node_info = null;
	private List<List<Integer>> cfg = null;
	private List<List<Integer>> prime_cfg = null;
	private int[][] distances;
	private int[][] previous;




	//	使用cfgparser.jar获取节点信息，并作为一个List<List<String>>输出
	private void get_node(String pathFile, String methodName) throws IOException {
		ProcessBuilder processBuilder= new ProcessBuilder();
		processBuilder.command("java", "-jar", cfgparser_path, pathFile, methodName);
		Process process = processBuilder.start();

		// 读取进程的输出流
		try (BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()))) {
			List<List<String>> output = new ArrayList<>();
			String line;
			while ((line = reader.readLine()) != null) {
				// 按行处理输出
				String[] parts = line.split("\\s+"); // 根据需要调整分隔符
				List<String> row = new ArrayList<>();
				for (String part : parts) {
					row.add(part);
				}
				output.add(row);
			}
			node_info = output;
			return ;
		}
	}

	//通过递归获取cfg
	public void get_cfg(int index_parent, int node_parent, int node_cmp, int node_gran, int if_else){
		List<Integer> branch = new ArrayList<>();
		int index_branch = 0;
		int node_last = node_parent;

		for(int i = index_parent;i < node_info.size(); i++){
			List<String> line_now = node_info.get(i);
			if(line_now.size()<8)break;
			if(Integer.parseInt(line_now.get(2)) != node_cmp )continue;

			if(line_now.get(8).contains("@")){
				String tab = line_now.get(8).substring(0,line_now.get(8).indexOf("@"));
				//处理after
				if(tab.contains("after")){
					branch.add(Integer.parseInt(line_now.get(1)));
				}

				int node_now = Integer.parseInt(line_now.get(1));
				if(node_now == if_else){
					cfg_addedge(node_last, node_gran);
					node_last = if_else - 2;
				}


				//处理for循环
				if(tab.contains("for-statement")){

					int node_condition = Integer.parseInt(node_info.get(i+1).get(1));
					int node_body = Integer.parseInt(node_info.get(i+2).get(1));
					cfg_addedge(node_last,node_now);
					node_last = node_condition;
					cfg_addedge(node_now,node_condition);
					cfg_addedge(node_condition,node_body);
					get_cfg(i+4,node_body,node_now,node_condition,-1);
					if(index_branch<branch.size()){
						node_last = branch.get(index_branch++);
						cfg_addedge(node_condition,node_last);
					}
				}
				//处理while循环
				if(tab.contains("while-statement")){
					int node_body = Integer.parseInt(node_info.get(i+1).get(1));
					cfg_addedge(node_last,node_now);
					node_last = node_now;
					cfg_addedge(node_now,node_body);
					get_cfg(i+2,node_body,node_now,node_now,-1);
					if(index_branch<branch.size()){
						node_last = branch.get(index_branch++);
						cfg_addedge(node_now,node_last);
					}
				}
				//处理if-else
				if(tab.contains("if-statement")){
					int node_next = branch.get(index_branch++);
					int node_body = Integer.parseInt(node_info.get(i+1).get(1));
					int node_else = Integer.parseInt(node_info.get(i+2).get(1));
					cfg_addedge(node_last,node_now);
					node_last = node_now;
					cfg_addedge(node_now,node_body);
					if(node_info.get(i+2).get(8).substring(0,node_info.get(i+2).get(8).indexOf("@")).contains("else")){
						get_cfg(i+3,node_body,node_now,node_next,node_else);
					}
					else{
						get_cfg(i+3,node_body,node_now,node_next,-1);
						cfg_addedge(node_now,node_next);
					}
				}
			}
		}
		//回边
		if(node_gran!=-2)
			cfg_addedge(node_last, node_gran);
		return ;
	}

	//通过循环拓展得到primecfg
	public void get_primecfg(){
		List<List<Integer>> now_cfg = new ArrayList<>(cfg);
		List<List<Integer>> ans_cfg = new ArrayList<>();
		while(!now_cfg.isEmpty()){
			int size = now_cfg.size();
			for(int i=0; i<size; i++){
				List<Integer> edge_now = now_cfg.get(i);
				int node_last = edge_now.get(edge_now.size() - 1);
				boolean if_extend = false;

				for(int j=0; j<cfg.size();j++){
					int left = cfg.get(j).get(0);
					int right = cfg.get(j).get(1);
					List<Integer> edge_new = new ArrayList<>(edge_now);
					if(left == node_last){
						if(!edge_now.contains(right)){
							edge_new.add(right);
							now_cfg.add(edge_new);
							if_extend = true;
						}else if(edge_now.get(0) == right){
							edge_new.add(right);
							if_extend = true;
							ans_cfg.add(edge_new);
						}
					}
				}

				if(!if_extend){
					ans_cfg.add(edge_now);
				}
			}

			for(int i=0; i<size;i++){
				now_cfg.remove(0);
			}
		}

		prime_cfg.addAll(ans_cfg);
		for(int i=0;i<ans_cfg.size();i++){
			for (int j=i+1;j<ans_cfg.size();j++){
				if(i!=j){
					List<Integer> list_i = ans_cfg.get(i);
					List<Integer> list_j = ans_cfg.get(j);
					if(isSubsequence(list_i,list_j)){
						prime_cfg.remove(list_i);
					}
					if(isSubsequence(list_j,list_i)){
						prime_cfg.remove(list_j);
					}
				}
			}
		}

	}


	@Override
	public int[][] getControlFlowGraphInArray(String pathFile, String methodName)
	{
		try {
			//初始化
			node_info = new ArrayList<>();
			cfg = new ArrayList<>();

			//获取node相关信息调用getcfg方法来得到流程图
			get_node(pathFile,methodName);
			get_cfg(1,0,-1,-2,-1);
			return listTOint(cfg);
		} catch (IOException e) {
			e.printStackTrace();
		}

		return null;
	}



	@Override
	public int[][] getTestRequirementsInArray(String pathFile, String methodName) 
	{
		try {
			//初始化
			node_info = new ArrayList<>();
			cfg = new ArrayList<>();
			prime_cfg = new ArrayList<>();

			//获取node相关信息调用getcfg方法来得到流程图
			get_node(pathFile,methodName);
			get_cfg(1,0,-1,-2,-1);

			//调用get_primecfg方法获得主路径并转换为int[][]格式
			get_primecfg();
			return listTOint(prime_cfg);

		} catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}

	
	@Override
	public int[][] getTestPathsInArray(String pathFile, String methodName) 
	{
		//初始化
		node_info = new ArrayList<>();
		cfg = new ArrayList<>();
		prime_cfg = new ArrayList<>();

		//获取node相关信息调用getcfg方法来得到流程图
		try {
			get_node(pathFile,methodName);
			get_cfg(1,0,-1,-2,-1);
			Floyd();

			//调用get_primecfg方法获得主路径并排序
			get_primecfg();
			Collections.sort(prime_cfg, new Comparator<List<Integer>>() {
				@Override
				public int compare(List<Integer> o1, List<Integer> o2) {
					return o1.size()-o2.size();
				}
			});

			int st=cfg.get(0).get(0);
			int en=cfg.get(cfg.size()-1).get(1);
			List<List<Integer>> test_path = new ArrayList<>();
			boolean used_path[] = new boolean[prime_cfg.size()];
			for(int i = prime_cfg.size() -1; i>=0;i--){
				if(used_path[i])continue;
				used_path[i]=true;
				boolean if_extend = false;
				List<Integer> edge_i = new ArrayList<>(prime_cfg.get(i));
				//向左侧拓展到起点
				if(edge_i.get(0)!=st){
					do {
						if_extend = false;
						for(int j=i-1;j>=0;j--){
							if(used_path[j])continue;
							List<Integer> edge_j = new ArrayList<>(prime_cfg.get(j));
							int match_length = findMatchLength(edge_i,edge_j);
							if(match_length>1){
								edge_i.addAll(0,edge_j.subList(0,edge_j.size() - match_length - 1));
								used_path[j]=true;
								if_extend =true;
								break;
							}
						}
					}while (if_extend);

					if (edge_i.get(0)!=st){
						List<Integer> path = get_shortest(st,edge_i.get(0));
						for (int j = 0;j < prime_cfg.size();j++)
							if(prime_cfg.get(j).equals(path))
								used_path[j]=true;
						path.remove(path.size()-1);
						edge_i.addAll(0,path);
					}

				}

				//向右拓展至终点
				if(edge_i.get(edge_i.size()-1)!=en){
					do {
						if_extend = false;
						for(int j=i-1;j>=0;j--){
							if(used_path[j])continue;
							List<Integer> edge_j = new ArrayList<>(prime_cfg.get(j));
							int match_length = findMatchLength(edge_j,edge_i);
							if(match_length>1){
								edge_i.addAll(edge_j.subList(match_length, edge_j.size()));
								used_path[j]=true;
								if_extend =true;
								break;
							}
						}
					}while (if_extend);

					if (edge_i.get(edge_i.size()-1)!=en){
						List<Integer> path = get_shortest(edge_i.get(edge_i.size()-1),en);
						for (int j = 0;j < prime_cfg.size();j++)
							if(prime_cfg.get(j).equals(path))
								used_path[j]=true;
						path.remove(0);
						edge_i.addAll(path);
					}

				}

				test_path.add(edge_i);
			}
			return listTOint(test_path);

		} catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}
	//为cfg添加边的函数
	private void cfg_addedge(int x, int y){
		List<Integer> new_edge =new ArrayList<>();
		new_edge.add(x);
		new_edge.add(y);
		if(cfg.contains(new_edge)||x==y)return;
		cfg.add(new_edge);
		return;
	}

	//判断list1是否list2的子序列
	public static boolean isSubsequence(List<Integer> list1, List<Integer> list2) {
		int i = 0; // 指针初始化
		for (Integer num : list2) {
			if (i < list1.size() && num.equals(list1.get(i))) {
				i++; // 当找到匹配的元素时，移动指针
			}
			if (i == list1.size()) {
				return true; // 如果所有的list1元素都匹配了，则返回true
			}
		}
		return i == list1.size(); // 如果所有list2元素都遍历完毕，还没有匹配完list1，则返回false
	}

	//获取两个list的首尾匹配度
	public static int findMatchLength(List<Integer> list1, List<Integer> list2) {
		int maxOverlapLength = 0;
		int minLength = Math.min(list1.size(), list2.size());

		// 遍历可能的重合长度，从1到minLength
		for (int i = 1; i <= minLength; i++) {
			// 取list1的首部子列表和list2的尾部子列表进行比较
			if (list1.subList(0, i).equals(list2.subList(list2.size() - i, list2.size()))) {
				maxOverlapLength = i;
			}
		}

		return maxOverlapLength;
	}

	//通过floyd算法获取当前图的点到点的最短路径
	public void Floyd(){
		int size = 0;
		for (List<Integer> edge: cfg){
			int from = edge.get(0);
			int to =edge.get(1);
			size = size > from ? size : from;
			size = size > to ? size : to;
		}
		size++;
		distances = new int[size][size];
		previous = new int[size][size];

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				distances[i][j] = Integer.MAX_VALUE;
				previous[i][j] = -1;
			}
			distances[i][i] = 0;
		}

		for (List<Integer> edge: cfg){
			int from = edge.get(0);
			int to =edge.get(1);
			distances[from][to] = 1;
			previous[from][to] = from;
		}

		for (int k = 0; k < distances.length; k++) {
			for (int i = 0; i < distances.length; i++) {
				for (int j = 0; j < distances.length; j++) {
					if (distances[i][k] != Integer.MAX_VALUE && distances[k][j] != Integer.MAX_VALUE
							&& (distances[i][k] + distances[k][j] < distances[i][j] || distances[i][j] == Integer.MAX_VALUE)) {
						distances[i][j] = distances[i][k] + distances[k][j];
						previous[i][j] = previous[k][j];
					}
				}
			}
		}


	}

	//获取最短路径
	public List<Integer>get_shortest(int start, int end){
		List<Integer>path = new ArrayList<>();
		Stack<Integer> stack = new Stack<>();
		int current = end;
		while (current != -1) {
			stack.push(current);
			current = previous[start][current];
		}
		while (!stack.isEmpty()) {
			path.add(stack.pop());
		}
		return path;
	}

	//生成int[][]
	public int[][] listTOint(List<List<Integer>> list) {
		int size = list.size();
		int[][] result = new int[size][]; // 创建二维数组
		for (int i=0;i<size;i++){
			result[i]=new int[list.get(i).size()];
		}

		int row = 0;
		for (List<Integer> innerList : list) {
			int col = 0;
			for (Integer number : innerList) {
				result[row][col++] = number; // 填充数字
			}
			row++;
		}
		return result;
	}
}
