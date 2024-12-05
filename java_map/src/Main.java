import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        // create a range
        final int RANGE_START = 0;
        final int RANGE_END = 1_000_000; //  RANGE is 0..1_000_000

        // create and fill HashMap
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = RANGE_START; i < RANGE_END; i++) {
            map.put(i, i);
        }

        // execute 100 iterations
        for (int t = 0; t < 100; t++) {
            long start = System.nanoTime(); // record start

            // compute sum
            int sum = 0;
            for (int i = RANGE_START; i < RANGE_END; i++) {
                Integer value = map.get(i);
                if (value != null) {
                    sum += value;
                }
            }

            if (t > 95) {
                long elapsed = System.nanoTime() - start;
                double elapsedMillis = elapsed / 1_000_000.0;
                System.out.printf("test round %d, sum: %d, elapsed: %.2f ms\n", t, sum,
                        elapsedMillis);
            }
        }
    }
}
