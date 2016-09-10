import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String[] args){

		Scanner std = new Scanner(System.in);
		
		BigInteger n,c,m, res;
		while(std.hasNextBigInteger()){
			n =std.nextBigInteger();
			c =std.nextBigInteger();
			m =std.nextBigInteger();
			res = c.modPow(n,m);
			System.out.println(res);		
		}

		std.close();
	}	

}

