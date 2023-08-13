import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

public class twoSum {
    public static int[] twoSum(int[] nums, int target) {


        //basic approach using two loops
//        for(int i=0;i<nums.length;i++)
//        {
//            for(int j=0;j<nums.length;j++)
//            {
//                if(i!=j && nums[i]+nums[j]==target)
//                    return new int[] {i,j};
//            }
//        }

        //not using this appraoch becasue if we
        // are using binary search we have to first sort the array and also map the
        //array positions in a new array which will require a lot of memory
//        for(int i=0;i<nums.length;i++)
//        {
//            int key=target-nums[i];
//            int h=Arrays.binarySearch(nums,key);
//
//            if(h<0)
//                h=(h+nums.length)%nums.length;
//            if(h!=i)
//            return new int[]{i,h};
//        }

        //using hashmaps
        //for every target we can first check
        //if it's divisible by 2 and the freq of that number is 2 if it is then we find the index
        HashMap<Integer, ArrayList<Integer>> h=new HashMap<>();
        for(int i=0;i<nums.length;i++)
        {
            ArrayList<Integer> l;
            if(h.containsKey(nums[i]))
            {
                l = h.get(nums[i]);
            }
            else
            {
                l = new ArrayList<>();
            }
            l.add(i);
            h.put(nums[i],l);
        }

        for(int i=0;i< nums.length;i++)
        {
            int key=target-nums[i];
            if(h.containsKey(key))
            {
                ArrayList<Integer> l=h.get(key);
                if(l.size()==1)
                {
                    if(l.get(0)==i)
                        continue;
                    else
                    {
                        return new int[]{i,l.get(0)};
                    }
                }
                else
                    return new int[]{l.get(0),l.get(1)};
            }
        }




        return new int[]{};




    }
    public static void main(String[] args) {


        int [] ans=twoSum(new int[] {0,4,3,0},0);
    }
}
