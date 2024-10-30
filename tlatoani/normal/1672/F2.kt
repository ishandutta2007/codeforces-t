import java.io.BufferedInputStream
import java.util.*

fun main() {
    val jin = FastScanner()
    val out = StringBuilder()
    repeat(jin.nextInt()) {
        val n = jin.nextInt()
        val xs = IntArray(n) { jin.nextInt() }
        val adj = Array(n + 1) { mutableListOf<Int>() }
        val inDegrees = IntArray(n + 1)
        for (x in xs) {
            val y = jin.nextInt()
            adj[x].add(y)
            inDegrees[y]++
        }
        val r = (1..n).maxBy(inDegrees::get)!!
        inDegrees[r] = 0
        val stack = ArrayDeque<Int>()
        stack.push(r)
        while (stack.isNotEmpty()) {
            val x = stack.pop()
            for (y in adj[x]) {
                inDegrees[y]--
                if (inDegrees[y] == 0) {
                    stack.push(y)
                }
            }
        }
        inDegrees[r] = 0
        out.appendln(if (inDegrees.all { it == 0 }) "AC" else "WA")
    }
    print(out)
}

class FastScanner {
    private val BS = 1 shl 16
    private val NC = 0.toChar()
    private val buf = ByteArray(BS)
    private var bId = 0
    private var size = 0
    private var c = NC
    private var `in`: BufferedInputStream? = null

    constructor() {
        `in` = BufferedInputStream(System.`in`, BS)
    }

    private val char: Char
        private get() {
            while (bId == size) {
                size = try {
                    `in`!!.read(buf)
                } catch (e: Exception) {
                    return NC
                }
                if (size == -1) return NC
                bId = 0
            }
            return buf[bId++].toChar()
        }

    fun nextInt(): Int {
        var neg = false
        if (c == NC) c = char
        while (c < '0' || c > '9') {
            if (c == '-') neg = true
            c = char
        }
        var res = 0
        while (c >= '0' && c <= '9') {
            res = (res shl 3) + (res shl 1) + (c - '0')
            c = char
        }
        return if (neg) -res else res
    }
}