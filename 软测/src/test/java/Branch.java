import org.apache.commons.math3.distribution.ZipfDistribution;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;



public class Branch {
    static ZipfDistribution zipf;
    @BeforeAll
    public static void create_Zipf(){
        int numberOfElements = 10;
        double exponent = 2.0;
        zipf = new ZipfDistribution(numberOfElements, exponent);

    }

    @Test
    public void Probability_BranchTest() {
        //针对distribution.ZipfDistribution.probability(final int x)的分支测试
        System.out.println("针对distribution.ZipfDistribution.probability(final int x)的分支测试:");
        int x = 0;
        double probability = zipf.probability(x);
        System.out.println("    Rank " + x + ": Probability = " + probability);
        x = 5;
        probability = zipf.probability(x);
        System.out.println("    Rank " + x + ": Probability = " + probability);
    }

    @Test
    public void logProbability_BranchTest() {
        //针对distribution.ZipfDistribution.logProbability(int x)的分支测试
        System.out.println("针对distribution.ZipfDistribution.logProbability(int x)的分支测试:");
        int x = 0;
        double probability = zipf.logProbability(x);
        System.out.println("    Rank " + x + ": Probability = " + probability);
        x = 10;
        probability = zipf.logProbability(x);
        System.out.println("    Rank " + x + ": Probability = " + probability);
    }

    @Test
    public void cumulativeProbability_BranchTest() {
        //针对distribution.ZipfDistribution.cumulativeProbability(final int x)的分支测试
        System.out.println("针对distribution.ZipfDistribution.cumulativeProbability(final int x)的分支测试:");
        int k = 0;
        double probability = zipf.cumulativeProbability(k);
        System.out.println("    Rank " + k + ": cumulativeProbability = " + probability);
        k = 5;
        probability = zipf.cumulativeProbability(k);
        System.out.println("    Rank " + k + ": cumulativeProbability = " + probability);
        k = 10;
        probability = zipf.cumulativeProbability(k);
        System.out.println("    Rank " + k + ": cumulativeProbability = " + probability);
    }
}
