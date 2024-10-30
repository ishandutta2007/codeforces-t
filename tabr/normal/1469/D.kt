import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var tt = int()
    while (tt-- > 0) {
        var n = int()
        var a = IntArray(n) { it + 1 }
        var ans = ArrayList<Pair<Int, Int>>()
        for (i in n - 2 downTo 1) {
            while ((a[n - 1] + a[i] - 1) / a[i] >= a[i]) {
                ans.add(Pair(n, i + 1))
                a[n - 1] = (a[n - 1] + a[i] - 1) / a[i]
            }
            ans.add(Pair(i + 1, n))
        }
        assert(a[n - 1] == 2)
        cout(ans.size)
        for (p in ans) {
            cout("${p.first} ${p.second}")
        }
    }
    print(output)
}

fun string() = input.readLine()
fun int() = string().toInt()
fun long() = string().toLong()
fun strings() = ArrayList(string().split(" "))
fun ints() = ArrayList(string().split(" ").map { it.toInt() })
fun longs() = ArrayList(string().split(" ").map { it.toLong() })
fun cout(s: String) = output.appendLine(s)
fun <T> cout(s: T) = output.appendLine(s.toString())
fun cout(s: IntArray) = output.appendLine(s.joinToString(" "))
fun cout(s: LongArray) = output.appendLine(s.joinToString(" "))
fun <T> cout(s: Array<T>) = output.appendLine(s.joinToString(" "))
fun <T> cout(s: Iterable<T>) = output.appendLine(s.joinToString(" "))
fun assert(x: Boolean) {
    if (!x) throw AssertionError()
}