import java.util.Random;

public class Thread_Random extends Thread
{
	char type;
	String caratteri = "";
	final String lettere = "abcdefghilmnopqrstuvz";
	Random random = new Random();
	
	public Thread_Random(char type){
		this.type = type;
	}

	@Override
	public void run(){
		if (type == 'A'){
			for (int i=0; i<6; i++){
				caratteri = caratteri.concat(String.valueOf(random.nextInt(10)));
			}
		}
		if (type == 'B') {
			for (int i=0; i<4; i++){
				caratteri = caratteri.concat(String.valueOf(lettere.charAt(random.nextInt(21))));
			}
		}
	}
}
