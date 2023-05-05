import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class containsDuplicate {

    public boolean containsDuplicate(int[] nums) {

        Map<Integer,Integer> h=new HashMap<>();
        for (int i : nums) {
            if(h.containsKey(i))
                return true;
            else
                h.put(i,1);

        }
        return false;
    }

    public void main(String[] args) {
        boolean ans = containsDuplicate(new int[]{1, 1, 1, 3, 3, 4, 3, 2, 4, 2});
        System.out.println(ans);
    }
}
