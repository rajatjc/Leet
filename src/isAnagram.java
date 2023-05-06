import java.util.HashMap;
import java.util.Map;
import java.util.stream.IntStream;

public class isAnagram {

    public static boolean isAnagram(String s, String t) {




        //Approach 1:
        //base case different length
        if(s.length()!=t.length())
            return false;

        //make array to store frequencies
        int[] a=new int[26];

        for(int i=0;i<s.length();i++)
        {
            //inc frequency for s
            a[s.charAt(i)-'a']++;
            //dec frequency for t

            a[t.charAt(i)-'a']--;
        }

        //check if sum(a) =0 using streams
        for (int i : a) {
            if(i!=0)
                return false;
        }


        return true;












    }

    public static void main(String[] args) {
        boolean ans = isAnagram("hello","hi");
        System.out.println(ans);
    }
}
