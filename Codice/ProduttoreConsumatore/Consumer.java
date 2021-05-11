public class Consumer extends Thread{ 

    private Buffer sharedLocation; 

    public Consumer(Buffer shared){ 

        super("Consumer"); 
        sharedLocation = shared;

    }

    public void run(){ 
        int sum = 0; 
        for (int count = 11; count <= 20; count++){ 
            try{
                Thread.sleep((int)(Math.random()*3001));
                sum += sharedLocation.get(); 
            }
            catch(InterruptedException exception){
                exception.printStackTrace(); 

            }
        } 
        System.err.println(getName()+" read values totaling: "+sum+"\nTerminating "+getName()+"."); 
    }



}