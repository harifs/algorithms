
public class Factorial {

	public long factorial(int n){
		return (n<=0)?1:n*factorial(n-1);
	}
	
	public static void main(String Args[]){
		Factorial fact = new Factorial();
		System.out.println(fact.factorial(-1));
	}
}
