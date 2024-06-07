import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;


public class MutantTest {
    static Mutant mutant_zipf;
    @BeforeAll
    public static void create_Zipf(){
        int numberOfElements = 10;
        double exponent = 2.0;
        mutant_zipf = new Mutant(numberOfElements, exponent);
    }

    @Test
    public void Probability_MutantTest() {
        //针对distribution.ZipfDistribution.probability(final int x)的强变异测试
        System.out.println("针对distribution.ZipfDistribution.probability(final int x)的强变异测试:");
        int x = 0;
        double probability = mutant_zipf.probability(x);
        System.out.println("    Rank " + x + ": Probability = " + probability);
    }

    @Test
    public void logProbability_MutantTest() {
        //针对distribution.ZipfDistribution.logProbability(int x)的强变异测试
        System.out.println("针对distribution.ZipfDistribution.logProbability(int x)的强变异测试:");
        int x = 10;
        double probability = mutant_zipf.logProbability(x);
        System.out.println("    Rank " + x + ": Probability = " + probability);
    }

    @Test
    public void cumulativeProbability_MutantTest() {
        //针对distribution.ZipfDistribution.cumulativeProbability(final int x)的强变异测试
        System.out.println("针对distribution.ZipfDistribution.cumulativeProbability(final int x)的强变异测试:");
        int k = 5;
        double probability = mutant_zipf.cumulativeProbability(k);
        System.out.println("    Rank " + k + ": cumulativeProbability = " + probability);
    }
}
