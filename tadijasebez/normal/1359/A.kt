import java.util.*
import java.math.*
import kotlin.math.*

fun readLn()=readLine()!!
fun readInt()=readLn().toInt()
fun readInts()=readLn().split(" ").map{it.toInt()}
fun readLong()=readLn().toLong()
fun readLongs()=readLn().split(" ").map{it.toLong()}

val out=mutableListOf<String>()
fun printLine(s:String){out.add(s)}
fun output(){println(out.joinToString("\n"))}

fun main(){
    val t=readInt()
    repeat(t){
        var (n,m,k)=readInts()
        var mx=min(n/k,m)
        m-=mx
        var sec=(m+k-2)/(k-1)
        printLine("${mx-sec}")
    }
    output()
}