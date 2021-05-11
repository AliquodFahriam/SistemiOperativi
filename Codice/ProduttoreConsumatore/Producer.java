public class Producer extends Thread{ 

    private Buffer sharedLocation; 

    public Producer(Buffer shared){ 
        super("Producer");//crea thread chiamato producer
        sharedLocation = shared; 

    }//end constructor

    public void run(){ 

        for (int count = 11; count <= 20; count++){ 

            try{ 
                Thread.sleep((int)(Math.random()*3001));
                sharedLocation.set(count);
            }

            catch (InterruptedException exception){ 
                exception.printStackTrace(); 
            }
            
        }
        System.err.println(getName()+" done producing "+ "\nTerminating "+getName()+".");
    }






}