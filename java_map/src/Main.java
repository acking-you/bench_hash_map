import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        // 创建一个范围常量
        final int RANGE_START = 0;
        final int RANGE_END = 1_000_000; //  RANGE 是 0..1_000_000

        // 创建并填充 HashMap
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = RANGE_START; i < RANGE_END; i++) {
            map.put(i, i);  // 模拟一个从 0 到 1_000_000 的映射
        }

        // 执行 100 次测试
        for (int t = 0; t < 100; t++) {
            long start = System.nanoTime(); // 记录开始时间

            // 计算 sum，获取 map 中每个 i 的值并累加
            int sum = 0;
            for (int i = RANGE_START; i < RANGE_END; i++) {
                Integer value = map.get(i);
                if (value != null) {
                    sum += value;  // 如果存在该键，累加它的值
                }
            }

            // 在第 96 到 100 轮时打印结果
            if (t > 95) {
                long elapsed = System.nanoTime() - start;
                // 转换为毫秒并打印
                double elapsedMillis = elapsed / 1_000_000.0;
                System.out.printf("test round %d, sum: %d, elapsed: %.2f ms\n", t, sum, elapsedMillis);
            }
        }
    }
}
