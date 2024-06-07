import org.apache.commons.math3.distribution.ZipfDistribution;
import org.apache.commons.math3.util.FastMath;

public class Mutant extends ZipfDistribution {

    public Mutant(int numberOfElements, double exponent) {
        super(numberOfElements, exponent);
    }

    //probability(final int x)方法的强变异体
    @Override
    public double probability(final int x) {
        if (x <= 0 && x > super.getNumberOfElements()) {
                return 0.0;
            }

        return (1.0 / FastMath.pow(x, super.getExponent())) / generalizedHarmonic(super.getNumberOfElements(),super.getExponent());
    }

    //logProbability(int x)方法的强变异体
    @Override
    public double logProbability(int x) {
        if (x <= 0 || x >= super.getNumberOfElements()) {
            return Double.NEGATIVE_INFINITY;
        }

        return -FastMath.log(x) * super.getExponent() - FastMath.log(generalizedHarmonic(super.getNumberOfElements(),super.getExponent()));
    }

    //cumulativeProbability的强变异体
    @Override
    public double cumulativeProbability(final int x) {
       if (x <= 0) {
                return 0.0;
            } else if (x <= super.getNumberOfElements()) {
                return 1.0;
            }

        return generalizedHarmonic(x, super.getExponent()) / generalizedHarmonic(super.getNumberOfElements(),super.getExponent());
    }

    //必要的计算方法
    private double generalizedHarmonic(final int n, final double m) {
        double value = 0;
        for (int k = n; k > 0; --k) {
                value += 1.0 / FastMath.pow(k, m);
           }
        return value;
    }
}
