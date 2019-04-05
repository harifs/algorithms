import java.util.*;
import java.util.concurrent.ConcurrentSkipListSet;

//Sets are list of unique elements - automatically de-duped at add
public class SetLessons {

	public static void main(String args[]){
		testSet();
	}

	public static void testSet(){
		Collection<Integer> c_set = new HashSet<>(Arrays.asList(1,1,1,2,3,4,5));
		//Default capacity and loadfactor are 16, 0.75
		// new HasSet<Integer>(1024,0.8); //can override the default capacity/loadfactor
		c_set.add(6);
		Collections.addAll(c_set, 7,7,7,8);
		System.out.println("Hashset...");
		System.out.println(c_set);
		System.out.println(c_set.hashCode());
		System.out.println("size: " + c_set.size());
		System.out.println("contains(5)" + c_set.contains(5));
		System.out.println("contains(1,2,3)" + c_set.containsAll(Arrays.asList(1,2,3)));

		System.out.println("All elements > 5");
		c_set.parallelStream().filter(x -> x>5).forEach( x -> {
			System.out.print(x+" ");
		});
		
		System.out.print("\n" + "sum of all elements excluding 6: ");
		c_set.stream().filter(c->c!=6).reduce((x,y) -> x+y).ifPresent(p -> System.out.println(p));
		
		LinkedHashSet<String> linkedset = new LinkedHashSet(Arrays.asList("adam","xbryan","carol","ydavid"));
		linkedset.add("fifth");
		linkedset.add("adam");
		linkedset.add("fifth");
		System.out.println("LinkedHashSet...");
		System.out.println(linkedset);
		Iterator<String> it = linkedset.iterator();
		while (it.hasNext()){
			if(it.next().startsWith("c"))
				it.remove();
		}
		System.out.println(linkedset);
		
		SortedSet<Integer> sorted = new TreeSet<>(); 
		Collections.addAll(sorted, 1,5,3,8,6,2,2,2,2,2,3,4,5);
		SortedSet<Integer> synced = Collections.synchronizedSortedSet(sorted);
		NavigableSet<Integer> skiplist = new ConcurrentSkipListSet<>(sorted);
		
		System.out.println("SortedSet/NavigableSet/SkipListSet");
		System.out.println(sorted);
		System.out.println("first:" + sorted.first());
		System.out.println("headset(3):" + synced.headSet(3));
		System.out.println("tailset(2):" + skiplist.tailSet(2));
		System.out.println("subset(3,6) - default: includes 3, excludes 6:" + skiplist.subSet(3, 6));
		System.out.println("subset(3,6) - include 3, include 6:" + skiplist.subSet(3,true,6,true));
		//Navigable only methods
		System.out.println("just lowerThan(4):" + skiplist.lower(4));
		System.out.println("lowerThanOrEqual(4):" + skiplist.floor(4));
		System.out.println("just higherThan(8) :" + skiplist.higher(8));
		System.out.println("higherThanOrEqual(8) :" + skiplist.ceiling(8));
		System.out.println("pollLast:" + skiplist.pollLast());
		System.out.println(skiplist);
		System.out.println(skiplist.descendingSet());
	}
}
