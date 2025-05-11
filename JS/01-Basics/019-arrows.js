console.log(this)

function runThis1() {
    username = 'VirusARzk'
    console.log(this.username)
}
runThis1()

const runThis2 = () => {
    username = 'VirusARzk'
    console.log(this.username) // undefined
}
runThis2()


function add1(a, b) {
    return a + b
}
console.log(add1(1, 2))

const add2 = function (a, b) {
    return a + b
}
console.log(add2(1, 2))

const add3 = (a, b) => a + b
console.log(add3(1, 2))

const add4 = (a, b) => (a + b)
console.log(add4(1, 2))

