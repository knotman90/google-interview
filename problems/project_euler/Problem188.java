package projectEuler;

import java.math.BigInteger;

public class Problem188 {
	public static BigInteger tetrarion_rem(BigInteger base, BigInteger exp){
		if(exp.equals(BigInteger.ONE))
			return base;
			
		BigInteger rest = tetrarion_rem(base, exp.add(BigInteger.ONE.negate()));
		return base.modPow(rest, BigInteger.TEN.pow(8));
	}
		
	public static void main(String[] args) {
		System.out.println(tetrarion_rem(BigInteger.valueOf(1777), BigInteger.valueOf(1855)));
	}
}
