import java.util.*;

public class MapLessons {
	public static void main(String args[]){
		testMap();
	}
	
	public static void testMap(){
		Hashtable<Integer,Integer> hashtable = new Hashtable<Integer,Integer>(){{
			put(1,10);
			put(3,30);
			put(2,20);
			put(4,40);
		}};
		
		System.out.println("Hashtable...");
		System.out.println(hashtable); //Prints keys sorted DESC
		hashtable.forEach((k,v) -> {
			System.out.println(k+"->"+v); //Iterates keys sorted ASC
		});
		hashtable.compute(1, (k,v) ->k*v ); //throws NPE if key is not present
		hashtable.computeIfPresent(3, (k,v) -> k+v);
		hashtable.computeIfAbsent(5, k->k*10 );
		System.out.println("size:" + hashtable.size());
		System.out.println("hashcode: " + hashtable.hashCode());
		System.out.println("get(3):" + hashtable.get(3));
		System.out.println("containsKey(4): " + hashtable.containsKey(4));
		System.out.println("containsValue(23): " + hashtable.containsValue(23));
		System.out.println(hashtable);
		System.out.println(hashtable.keySet());

		HashMap<Integer,Integer> hashMap = new HashMap<Integer,Integer>(){{
			put(1,10);
			put(3,30);
			put(2,20);
			put(4,40);
		}};
		
		System.out.println("HashMap...");
		hashMap.forEach((k,v) -> {
			System.out.println(k+"->"+v); //Iterates keys sorted ASC
		});
		hashMap.entrySet().forEach( x -> {
			System.out.println(x.getKey() + "->" + x.getValue());
		});
		System.out.println(hashMap.values());
		
		//SortedMap, NavigableMap - can get head/tail/subset
		TreeMap<Integer,Integer> treemap = new TreeMap<Integer,Integer>(){{
			put(1,10);
			put(3,30);
			put(2,20);
			put(4,40);
		}};
		System.out.println("TreeMap...");
		treemap.forEach((k,v) -> {
			System.out.println(k+"->"+v); //Iterates keys sorted ASC
		});
		
		System.out.println("first entry:" + treemap.firstKey() + "->" + treemap.firstEntry().getValue() );
		Map.Entry<Integer,Integer> entry = treemap.pollLastEntry();
		System.out.println("polled last" + entry.getKey() + "->" + entry.getValue() );
		System.out.println(treemap);
		System.out.println("submap(2,3)" + treemap.subMap(2,true,3,true));
	}
}
