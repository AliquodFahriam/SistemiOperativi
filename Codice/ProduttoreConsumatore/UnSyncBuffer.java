public class UnSyncBuffer implements Buffer{ 

    private int buffer = -1; //condiviso da producer e consumer
    
    public void set(int value){ 
        System.err.println(Thread.currentThread().getName()+" writes "+ value); 
        buffer = value;
    }//end Set 

    public int get(){ 
        System.err.println(Thread.currentThread().getName()+" reads "+buffer);
        return buffer; 
    }//end get 

}//end class UnSyncronizedBuffer 