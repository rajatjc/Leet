import java.util.ArrayList;
import java.util.List;

public class groupAnagrams {

    interface helper{
        boolean isAna(String s,String t);
    }
    public static List<List<String>> groupAnagrams(String[] strs) {



      helper gg=new helper() {
          @Override
          public boolean isAna(String s, String t) {

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
      };




        List<List<String>> l=new ArrayList<List<String>>();
        for (String str : strs) {
            int flag=0;
            for (int i=0;i<l.size();i++) {

                List<String> singleL=l.get(i);
                String s=singleL.get(0);
                if(gg.isAna(str,s))
                {
                    flag=1;
                    singleL.add(str);
                    l.remove(i);
                    l.add(singleL);
                    break;
                }

            }
            if(flag==0)
            {
                List<String> newL=new ArrayList<>();
                newL.add(str);
                l.add(newL);
            }
        }

        return l;
    }
    public static void main(String[] args) {


        List<List<String>> ans=groupAnagrams(new String[]{"eat","tea","tan","ate","nat","bat"});

        ans.forEach(System.out::println);
    }
}
