import org.junit.After;
import org.junit.Before;
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.assertFalse;

import static org.junit.jupiter.api.Assertions.assertTrue;

public class YeZhenghao {

    static ArrayList<String> list;
    @BeforeAll
    public static void create_array(){
        list = new ArrayList<>();

    }

    @AfterAll
    public static void show_array(){
        list = null;
    }

    @Test
    public void remove_index_Test() {
        //完成remove (int index) 分支覆盖和主路径覆盖任务
        list.clear();
        list.add("0000");
        list.add("1111");
        System.out.println("remove_index_BranchTest: origin array:"+list.toString());
        try{
            list.remove(0);
            list.remove(0);
        }catch (Exception e){
            System.err.println("Error closing reader: " + e.getMessage());
        }
        System.out.println("remove_index_BranchTest: after array:"+list.toString());
    }

    @Test
    public void remove_object_BranchTest(){
        //完成remove (Object o) 分支覆盖任务
        list.clear();
        list.add(null);
        list.add("testString");
        System.out.println("remove_object_BranchTest: origin array:"+list.toString());
        try{
            list.remove(null);
            list.remove(null);
            list.remove("testString");
            list.remove("testString");
        }catch (Exception e){
            System.err.println("Error closing reader: " + e.getMessage());
        }
        System.out.println("remove_object_BranchTest: after array:"+list.toString());
    }

    @Test
    public void remove_object_CTRC(){
        //完成remove (Object o) 主路径覆盖和完全回路覆盖任务
        list.clear();
        list.add("0000");
        list.add("1111");
        list.add(null);
        list.add("testString");
        System.out.println("remove_object_PPC: origin array:"+list.toString());
        try{
            list.remove(null);
            list.remove(null);
            list.remove("testString");
            list.remove("testString");
        }catch (Exception e){
            System.err.println("Error closing reader: " + e.getMessage());
        }
        System.out.println("remove_object_PPC: after array:"+list.toString());
    }
}
