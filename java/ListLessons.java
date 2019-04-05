import java.util.*;

//Lists - allow Duplicates
public class ListLessons {

	public static void testList(){
		Collection<String> c_array = new ArrayList<String>(){{
			add("abc");
			add("xyz");
		}};
		c_array.add("pqr");
		c_array.add("pqr");
		c_array.add("pqr");
		Collections.addAll(c_array,"test1","test2");

		System.out.println("Collections ArrayList...");
		System.out.println( c_array);
		System.out.println("size:" + c_array.size());
		System.out.println("Contains pqr:" + c_array.contains("pqr"));
		c_array.remove("xyz");
		System.out.println( c_array);

		LinkedList<String> l_linkedList = new LinkedList(Arrays.asList("list1","list2"));
		l_linkedList.add("list3");
		l_linkedList.addFirst("list3");
		l_linkedList.addLast("list4");

		System.out.println("\nLinkedList...");
		System.out.println(l_linkedList);
		System.out.println("size:" + l_linkedList.size());
		System.out.println("Contains pqr:" + l_linkedList.contains("pqr"));
		System.out.println("getFirst:" +  l_linkedList.getFirst());
		System.out.println("removeLast:" +  l_linkedList.removeLast());
		System.out.println( l_linkedList);


		Vector<Double> l_vector = new Vector<>();
		Vector<Double> l_vector2 = new Vector<>();
		l_vector.addElement(1.0);
		l_vector.add(2.0);
		Collections.addAll(l_vector,3.0,3.0,4.0,5.0,6.1,7.2);
		l_vector2.addAll(l_vector); //copying elements of one list into another

		System.out.println("\nVector...");
		System.out.println(l_vector);
		System.out.println("size:" + l_vector.size());
		System.out.println("Contains 3.0:" + l_vector.contains(3.0));
		System.out.println("Removed: " + l_vector.remove(2));
		l_vector.removeElementAt(0);
		System.out.println("Replaced: " + l_vector.set(4,1.8) + " with 1.8");
		System.out.println(l_vector);
		l_vector.setElementAt(1.9, 2);
		l_vector.insertElementAt(2.2, 3);
		l_vector.removeElement(2.0);
		System.out.println(l_vector);

		Stack<Integer> v_stack = new Stack();
		Collections.addAll(v_stack, 1,2,3,4,5);
		System.out.println("\nStack...");
		System.out.println(v_stack);
		System.out.println(v_stack.capacity());
		System.out.println(v_stack.peek());
		System.out.println(v_stack.pop());
		System.out.println(v_stack);
		System.out.println("to get 1 we need to pop " + v_stack.search(1) + " times");

		Queue<Integer> q_queue = new PriorityQueue();
		q_queue.add(1);
		Collections.addAll(q_queue, 2,3,4,5,6);

		System.out.println("\nQueue...");
		System.out.println(q_queue);
		System.out.println("Size: " + q_queue.size());
		//q_queue.clear();
		System.out.println("peek: " + q_queue.peek()); //null if queue empty
		System.out.println("element: " + q_queue.element()); //exception if queue is empty
		System.out.println("remove: " + q_queue.remove()); //exception of queue empty
		System.out.println(q_queue);
		System.out.println("offer(8): " + q_queue.offer(8));
		System.out.println("add(87): " + q_queue.add(8));
		System.out.println("Contains 6" + q_queue.contains(6));
		System.out.println("Contains 4,5,6,0: " + q_queue.containsAll(Arrays.asList(4,5,6,0)));
		System.out.println(q_queue);
		System.out.println("printing all...");
		q_queue.forEach(x -> {
			System.out.print(x+" ");
		});
		System.out.println("\n"+q_queue);

		Deque<Integer> deque = new ArrayDeque();
		Collections.addAll(deque,1,2,3,4,5);
		deque.push(6);
		System.out.println("\nDeque...");
		System.out.println("pop: "+ deque.pop());
		System.out.println("peekFirst: "+ deque.peekFirst());
		System.out.println("offerFirst: "+ deque.offerFirst(0));
		System.out.println(deque);
	}
	
	public static void main(String args[]){
		testList();
	}
	
}
