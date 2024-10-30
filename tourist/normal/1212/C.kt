private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
    var (n, k) = readInts()
    var a = readInts().toMutableList()
    a.sort()
    if (k == 0) {
        if (a[0] == 1) println(-1)
        else println(1)
        return
    }
    if (k < n && a[k - 1] == a[k]) {
        println(-1)
    } else {
        println(a[k - 1])
    }
}