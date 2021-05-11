public class es_4 
{
	public static void main(String[] args) {
		try {
			String result = createString();

			System.out.println("result = " + result);
		} catch (InterruptedException exp) {
			System.out.println(exp);
		}
	}	

	public static String createString() throws InterruptedException{
		Thread_Random thread1 = new Thread_Random('A');
		Thread_Random thread2 = new Thread_Random('B');

		thread1.start();
		thread2.start();

		thread1.join();
		thread2.join();

		System.out.println("string2: " + thread2.caratteri);
		System.out.println("string1: " + thread1.caratteri);

		String result = "";

		result = result.concat(thread1.caratteri.substring(0, 2));
		result = result.concat(thread2.caratteri.substring(0, 2));
		result = result.concat(thread1.caratteri.substring(2, 4));
		result = result.concat(thread2.caratteri.substring(2, 4));
		result = result.concat(thread1.caratteri.substring(4, 6));

		return result;
	}
}
