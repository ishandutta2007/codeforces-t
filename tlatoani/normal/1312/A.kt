fun main() = (1..readLine()!!.toInt()).forEach { println(if (readLine()!!.split(" ").map(String::toInt).reduce { n, m -> n % m} == 0) "YES" else "NO") }