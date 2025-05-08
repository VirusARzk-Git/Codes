const heros = ['superman', 'batman', 'wonderwoman']
heros.shift();  // removes the first element of the array 
heros.unshift("aquaman");   // adds an element to the beginning of the array
console.log(heros);


let myObj = {
    name: 'John',
    age: 25,
    isMale: true,
}

const myFunc = function () {
    console.log('Hello World');
}

console.log(typeof heros);
console.log(typeof myObj);
console.log(typeof myFunc);