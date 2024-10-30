import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.charset.Charset;
import java.util.*;
 
 
public class CFContest {
    public static void main(String[] args) throws Exception {
        boolean local = System.getProperty("ONLINE_JUDGE") == null;
        boolean async = true;
 
        Charset charset = Charset.forName("ascii");
 
        FastIO io = local ? new FastIO(new FileInputStream("D:\\DATABASE\\TESTCASE\\Code.in"), System.out, charset) : new FastIO(System.in, System.out, charset);
        Task task = new Task(io, new Debug(local));
 
        if (async) {
            Thread t = new Thread(null, task, "dalt", 1 << 27);
            t.setPriority(Thread.MAX_PRIORITY);
            t.start();
            t.join();
        } else {
            task.run();
        }
 
        if (local) {
            io.cache.append("\n\n--memory -- \n" + ((Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory()) >> 20) + "M");
        }
 
        io.flush();
    }
 
    public static class Task implements Runnable {
        final FastIO io;
        final Debug debug;
        int inf = (int) 1e8;
 
        public Task(FastIO io, Debug debug) {
            this.io = io;
            this.debug = debug;
        }
 
        @Override
        public void run() {
            solve();
        }
 
        int n;
        int m;
 
        public void solve() {
            int n = io.readInt();
            int m = n + n;
            int[] val = new int[m];
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                    val[i] = i * 2;
                    val[i + n] = i * 2 + 1;
                } else {
                    val[i] = i * 2 + 1;
                    val[i + n] = i * 2;
                }
            }
 
            long sum = 0;
            for (int i = 0; i < n; i++) {
                sum += val[i];
            }
            long min, max;
            min = max = sum;
            for (int i = 1; i < m; i++) {
                sum -= val[i - 1];
                sum += val[(i - 1 + n) % m];
                min = Math.min(sum, min);
                max = Math.max(sum, max);
            }
            if (max - min > 1) {
                io.cache.append("NO");
                return;
            }
            io.cache.append("YES\n");
            for (int v : val) {
                io.cache.append(v + 1).append(' ');
            }
        }
    }
 
    public static class Randomized {
        static Random random = new Random();
 
        public static double nextDouble(double min, double max) {
            return random.nextDouble() * (max - min) + min;
        }
 
        public static void randomizedArray(int[] data, int from, int to) {
            to--;
            for (int i = from; i <= to; i++) {
                int s = nextInt(i, to);
                int tmp = data[i];
                data[i] = data[s];
                data[s] = tmp;
            }
        }
 
        public static void randomizedArray(long[] data, int from, int to) {
            to--;
            for (int i = from; i <= to; i++) {
                int s = nextInt(i, to);
                long tmp = data[i];
                data[i] = data[s];
                data[s] = tmp;
            }
        }
 
        public static void randomizedArray(double[] data, int from, int to) {
            to--;
            for (int i = from; i <= to; i++) {
                int s = nextInt(i, to);
                double tmp = data[i];
                data[i] = data[s];
                data[s] = tmp;
            }
        }
 
        public static void randomizedArray(float[] data, int from, int to) {
            to--;
            for (int i = from; i <= to; i++) {
                int s = nextInt(i, to);
                float tmp = data[i];
                data[i] = data[s];
                data[s] = tmp;
            }
        }
 
        public static <T> void randomizedArray(T[] data, int from, int to) {
            to--;
            for (int i = from; i <= to; i++) {
                int s = nextInt(i, to);
                T tmp = data[i];
                data[i] = data[s];
                data[s] = tmp;
            }
        }
 
        public static int nextInt(int l, int r) {
            return random.nextInt(r - l + 1) + l;
        }
    }
 
    /**
     * Mod operations
     */
    public static class Modular {
        int m;
 
        public Modular(int m) {
            this.m = m;
        }
 
        public int valueOf(int x) {
            x %= m;
            if (x < 0) {
                x += m;
            }
            return x;
        }
 
        public int valueOf(long x) {
            x %= m;
            if (x < 0) {
                x += m;
            }
            return (int) x;
        }
 
        public int mul(int x, int y) {
            return valueOf((long) x * y);
        }
 
        public int mul(long x, long y) {
            x = valueOf(x);
            y = valueOf(y);
            return valueOf(x * y);
        }
 
        public int plus(int x, int y) {
            return valueOf(x + y);
        }
 
        public int plus(long x, long y) {
            x = valueOf(x);
            y = valueOf(y);
            return valueOf(x + y);
        }
 
        @Override
        public String toString() {
            return "mod " + m;
        }
    }
 
    public static class FastIO {
        public final StringBuilder cache = new StringBuilder(1 << 20);
        private final InputStream is;
        private final OutputStream os;
        private final Charset charset;
        private StringBuilder defaultStringBuf = new StringBuilder(1 << 8);
        private byte[] buf = new byte[1 << 13];
        private int bufLen;
        private int bufOffset;
        private int next;
 
        public FastIO(InputStream is, OutputStream os, Charset charset) {
            this.is = is;
            this.os = os;
            this.charset = charset;
        }
 
        public FastIO(InputStream is, OutputStream os) {
            this(is, os, Charset.forName("ascii"));
        }
 
        private int read() {
            while (bufLen == bufOffset) {
                bufOffset = 0;
                try {
                    bufLen = is.read(buf);
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                if (bufLen == -1) {
                    return -1;
                }
            }
            return buf[bufOffset++];
        }
 
        public void skipBlank() {
            while (next >= 0 && next <= 32) {
                next = read();
            }
        }
 
        public int readInt() {
            int sign = 1;
 
            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+' ? 1 : -1;
                next = read();
            }
 
            int val = 0;
            if (sign == 1) {
                while (next >= '0' && next <= '9') {
                    val = val * 10 + next - '0';
                    next = read();
                }
            } else {
                while (next >= '0' && next <= '9') {
                    val = val * 10 - next + '0';
                    next = read();
                }
            }
 
            return val;
        }
 
        public long readLong() {
            int sign = 1;
 
            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+' ? 1 : -1;
                next = read();
            }
 
            long val = 0;
            if (sign == 1) {
                while (next >= '0' && next <= '9') {
                    val = val * 10 + next - '0';
                    next = read();
                }
            } else {
                while (next >= '0' && next <= '9') {
                    val = val * 10 - next + '0';
                    next = read();
                }
            }
 
            return val;
        }
 
        public double readDouble() {
            boolean sign = true;
            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+';
                next = read();
            }
 
            long val = 0;
            while (next >= '0' && next <= '9') {
                val = val * 10 + next - '0';
                next = read();
            }
            if (next != '.') {
                return sign ? val : -val;
            }
            next = read();
            long radix = 1;
            long point = 0;
            while (next >= '0' && next <= '9') {
                point = point * 10 + next - '0';
                radix = radix * 10;
                next = read();
            }
            double result = val + (double) point / radix;
            return sign ? result : -result;
        }
 
        public String readString(StringBuilder builder) {
            skipBlank();
 
            while (next > 32) {
                builder.append((char) next);
                next = read();
            }
 
            return builder.toString();
        }
 
        public String readString() {
            defaultStringBuf.setLength(0);
            return readString(defaultStringBuf);
        }
 
        public int readLine(char[] data, int offset) {
            int originalOffset = offset;
            while (next != -1 && next != '\n') {
                data[offset++] = (char) next;
                next = read();
            }
            return offset - originalOffset;
        }
 
        public int readString(char[] data, int offset) {
            skipBlank();
 
            int originalOffset = offset;
            while (next > 32) {
                data[offset++] = (char) next;
                next = read();
            }
 
            return offset - originalOffset;
        }
 
        public int readString(byte[] data, int offset) {
            skipBlank();
 
            int originalOffset = offset;
            while (next > 32) {
                data[offset++] = (byte) next;
                next = read();
            }
 
            return offset - originalOffset;
        }
 
        public char readChar() {
            skipBlank();
            char c = (char) next;
            next = read();
            return c;
        }
 
        public void flush() {
            try {
                os.write(cache.toString().getBytes(charset));
                os.flush();
                cache.setLength(0);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
 
        public boolean hasMore() {
            skipBlank();
            return next != -1;
        }
    }
 
    public static class Debug {
        private boolean allowDebug;
 
        public Debug(boolean allowDebug) {
            this.allowDebug = allowDebug;
        }
 
        public void assertTrue(boolean flag) {
            if (!allowDebug) {
                return;
            }
            if (!flag) {
                fail();
            }
        }
 
        public void fail() {
            throw new RuntimeException();
        }
 
        public void assertFalse(boolean flag) {
            if (!allowDebug) {
                return;
            }
            if (flag) {
                fail();
            }
        }
 
        private void outputName(String name) {
            System.out.print(name + " = ");
        }
 
        public void debug(String name, int x) {
            if (!allowDebug) {
                return;
            }
 
            outputName(name);
            System.out.println("" + x);
        }
 
        public void debug(String name, long x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println("" + x);
        }
 
        public void debug(String name, double x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println("" + x);
        }
 
        public void debug(String name, int[] x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println(Arrays.toString(x));
        }
 
        public void debug(String name, long[] x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println(Arrays.toString(x));
        }
 
        public void debug(String name, double[] x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println(Arrays.toString(x));
        }
 
        public void debug(String name, Object x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println("" + x);
        }
 
        public void debug(String name, Object... x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println(Arrays.deepToString(x));
        }
    }
}