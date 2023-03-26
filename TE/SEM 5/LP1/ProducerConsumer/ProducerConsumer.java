import java.util.*;

class Producer implements Runnable
{
	private final List<Integer> taskQueue;
	private final int MAX_CAPACITY;
	public Producer(List<Integer> sharedQueue, int size)
	{
		this.taskQueue = sharedQueue;
		this.MAX_CAPACITY = size;
	}
	

	public void run()
	{
		int counter = 1;
		while(true)
		{
			try
			{
				produce(counter++);
			}
			catch(InterruptedException e)
			{
				System.out.println("Interrupted Exception at Producer code !");
				e.printStackTrace();
			}
		}  
	}
	
	private void produce(int i) throws InterruptedException
	{
		synchronized(taskQueue)
		{
			while(taskQueue.size() == MAX_CAPACITY)
			{
				System.out.println("Queue Overflow !!!");
				System.out.println(Thread.currentThread().getName()+" is waiting, size: "+ taskQueue.size());
				taskQueue.wait();
			}
			Thread.sleep(1000);  //Thread will wait for a second
			taskQueue.add(i); //add to the task Queue
			System.out.println("Produced: "+i);
			taskQueue.notifyAll();
		}
	}
}

class Consumer implements Runnable
{
	private final List<Integer> taskQueue;
	public Consumer(List<Integer> sharedQueue)
	{
		this.taskQueue = sharedQueue;
	}
	
	public void run()
	{
		while(true)
		{
			try
			{
				consume();
			}
			catch(InterruptedException e)
			{
				System.out.println("Interrupted Exception at consumer code");
				e.printStackTrace();
			}
		}
	}
	
	private void consume() throws InterruptedException 
	{
		synchronized(taskQueue)
		{
			while(taskQueue.isEmpty())
			{
				System.out.println("Queue Underflow !!!");
				System.out.println(Thread.currentThread().getName()+" is waiting, size: "+ taskQueue.size());
				taskQueue.wait();
			}
			Thread.sleep(1000);  //Thread will wait for a second
			int i =(Integer)taskQueue.remove(0); //remove from front
			System.out.println("Consumed: "+i);
			taskQueue.notifyAll();
			
		}
	}
}

public class ProducerConsumer
{
	public static void main(String args[])
	{
		System.out.println(">-------------< Producer-Consumer Problem >-------------<\n\n");
		List<Integer> taskQueue = new ArrayList<Integer>();
		int MAX_CAPACITY = 5;
		Thread TP = new Thread(new Producer(taskQueue,MAX_CAPACITY),"Producer");
		Thread TC = new Thread(new Consumer(taskQueue),"Consumer");
		TP.start();
		TC.start();
	}
}
