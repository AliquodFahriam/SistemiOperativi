public class Thread_Count extends Thread 
{

	int sum=0;
	private String type;
	private int[] array;

	public Thread_Count(int[] array, String type){
		this.array = array;
		this.type = type;
	}

	public void run(){

		if( type.equals("p")){

			for (int element : array) {
				if (element % 2 == 0){
					this.sum+=element;
				}
			}

		}else if(type.equals("d")){

			for (int element : array) {
				if (element % 2 != 0) {
					this.sum += element;
				}
			}

		}
	}	
}
