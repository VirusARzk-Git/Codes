let a = 10
const b = 20
var c = 30 
// var is function scoped
// let and const are block scoped

console.log(a, b, c)

{
    let a = 40
    const b = 50
    var c = 60
    console.log(a, b, c)
}

console.log(a, b, c)

console.log(addOne(10)) // works as it is a function declaration and hoisting works here as well
function addOne(val){
    return val + 1
}

// console.log(addTwo(10)) // doesn't work as it is a const variable and hoisting doesn't work here as it is a function expression and not a function declaration
const addTwo = function(val){
    return val + 2
}
console.log(addTwo(10))
