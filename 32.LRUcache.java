// https://leetcode.com/problems/lru-cache/

class LRUCache {
    class Entry{
        public int value = 0;
        public int count = 1;
    }
    
    private Map<Integer,Entry> map;
    private Queue<Integer> q;
    private int size, capacity;
    
    public LRUCache(int capacity) {
        map = new HashMap<Integer,Entry>(capacity*2);
        q = new LinkedList<Integer>();
        this.size = 0;
        this.capacity = capacity;
    }
    
    public int get(int key) {
        if(map.containsKey(key)){
            Entry e = map.get(key);
            e.count++;
            q.add(key);
            return e.value;
        }
        return -1;
    }
    
    public void put(int key, int value) {
        if(map.containsKey(key)){
            Entry e = map.get(key);
            e.value = value;
            e.count++;
            q.add(key);
        }
        else{
            map.put(key, new Entry());
            map.get(key).value = value;
            q.add(key);
            size++;
            if(size>capacity){
                while(map.get(q.element()).count!=1){
                    int k = q.poll();
                    map.get(k).count -= 1;
                }
                int old_key = q.poll();
                map.remove(old_key);
                size--;
            }
        }
    }
}

