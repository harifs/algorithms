public class MyThread{
	public static void main(String Args[]){
		//new ThreadTest().start();
		//new ThreadTest("customName").start();
		
		Runnable runnable1 = new PrintFactorial(13);
		Runnable runnable2 = new PrintFactorial(16);
		Runnable runnable3 = new PrintFactorial(3);
		Runnable runnable4 = new PrintFactorial(19);
		Runnable runnable5 = new PrintFactorial(10);
		
		//Defining Runnable with Lambda Expression
		Runnable runnable6 = () -> {
			System.out.println("Starting Thread "+ Thread.currentThread().getName());
			try {
				Thread.sleep(2000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			System.out.println("Ending Thread "+ Thread.currentThread().getName());
		};
		
		Thread thread1 = new Thread(runnable1);
		Thread thread2 = new Thread(runnable2);
		Thread thread3 = new Thread(runnable3);
		Thread thread4 = new Thread(runnable4);
		Thread thread5 = new Thread(runnable5);
		Thread thread6 = new Thread(runnable6);
		
		thread1.start();
		thread2.start();
		thread3.start();
		thread4.start();
		thread5.start();
		thread6.start();
	}
}

//Thread class that Implements runnable
class PrintFactorial implements Runnable{
	private int n;
	private int factorial=1;
	
	PrintFactorial(int number){
		this.n = number;
	}
	
	public void run(){
		System.out.println("Factorial of "+n+": starting...");
		if(n<0)
			System.out.println(0);
		else if(n<2)
			System.out.println(1);
		else{
			for(int i=1;i<=n;i++)
				factorial*=i;
			System.out.println("Factorial of "+n+" is " + factorial);
		}
	}
}

//Threadclass that extends thread
class ThreadTest extends Thread{
	public ThreadTest(){
		super();
	}
	public ThreadTest(String str){
		super(str);
	}
	public void run() {
		for (int i = 0; i < 5; i++) {
			System.out.println(i+ ".) starting " + Thread.currentThread().getName());
			try {
				sleep(2000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			System.out.println(i+ ".) ending " + Thread.currentThread().getName());
		}
	}
}

