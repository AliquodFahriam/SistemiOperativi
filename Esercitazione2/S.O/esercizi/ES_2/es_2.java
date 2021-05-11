public class es_2
{
	
	public static void main(String[] args) {
		int[] array = {5, 2, 5, 2, 5, 2, 5, 2, 5};
		
		try{
			int sum = getSUM(array);

			System.out.println("SUM: " + sum);
		} catch (InterruptedException exp){
			System.out.println(exp);
		}
		
	}


	public static int getSUM(int[] array) throws InterruptedException {	
		Thread_Count thread1 = new Thread_Count(array, "p");
		Thread_Count thread2 = new Thread_Count(array, "d");

		thread1.start();
		thread2.start();

		thread1.join();
		thread2.join();

		System.out.println("sum 1: " + thread1.sum);
		System.out.println("sum 2: " + thread2.sum);

		return thread1.sum + thread2.sum;
	}

}