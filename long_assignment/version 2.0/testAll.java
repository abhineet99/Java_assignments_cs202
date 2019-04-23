import org.junit.runner.RunWith;
import org.junit.runners.Suite;
import org.junit.runners.Suite.SuiteClasses;

@RunWith(Suite.class)
@SuiteClasses({testClass.class})
public class testAll{
    public static void main(String[] args){
        System.out.println("Test in progress");
    }
}