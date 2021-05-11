public class SharedBufferTest{ 

    public static void main (String [] args){ 

        //create shared object used by threads

        Buffer sharedLocation = new UnSyncBuffer(); 

        //create producer and consumer object 
        Producer producer = new Producer(sharedLocation); 
        Consumer consumer = new Consumer(sharedLocation); 

        producer.start(); 
        consumer.start();


    }//end Main 



}//end class SharedBufferTest