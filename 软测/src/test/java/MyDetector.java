import org.graalvm.polyglot.Context;
import org.graalvm.polyglot.Value;
import reachbot.tool.BaseDetector;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.StringReader;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class MyDetector extends BaseDetector {

	@Override
	public String getCondition(String pathFile, String methodName, String id)
	{
		String methodCode = getMethodCode(pathFile, methodName);
		List<String> condition_list = new ArrayList<>();	//统计条件语句
		List<Integer> if_list = new ArrayList<>();		//统计转折点，1代表if语句为真，0代表为假
		int cnt=0;		//统计递归深度
		String target = "System.out.println("+'"'+id+'"'+");";

		//一行行读取代码，并判断代码
		try (BufferedReader reader = new BufferedReader(new StringReader(methodCode))) {
			String line;
			while ((line = reader.readLine()) != null) {
				//读取 if 语句
				String regex = "\\bif\\s*\\((.*?)\\)";
				Pattern pattern = Pattern.compile(regex);
				Matcher matcher = pattern.matcher(line);
				if (matcher.find()) {
					if(condition_list.size()>cnt){
						condition_list.set(cnt,'('+matcher.group(1).toString()+')');
						if_list.set(cnt,1);
					}
					condition_list.add('('+matcher.group(1).toString()+')');
					if_list.add(1);
					continue;
				}

				//读取 { 和 } 字符
				if(line.contains("{")){
					cnt++;
					continue;
				}

				if(line.contains("}")){
					cnt--;
					continue;
				}

				//读取 else 字符
				if(line.contains("else")){
					if_list.set(cnt,0);
					continue;
				}

				//读取目标语句
				if(line.contains(target)){
					String ans="";
					for(int i=0;i<cnt;i++){
						if(i!=0)ans+=" && ";
						if(if_list.get(i)==0){
							ans+='!';
						}
						ans+=condition_list.get(i);
					}
					return ans;
				}
			}
		} catch (IOException e) {
			e.printStackTrace();
		}

		return super.getCondition(pathFile, methodName, id);
	}

	@Override
	public boolean getReachability(String pathFile, String methodName, String id)
	{
		//获取条件语句
		String condition = getCondition(pathFile,methodName,id);

		//通过js引擎来判断
		Context context = Context.create();
		Value result = context.eval("js", condition);
		return result.asBoolean();

	}


}
