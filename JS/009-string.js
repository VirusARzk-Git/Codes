const name = 'Aaditya';
const age = 23;
const city = 'Deoghar';

// String interpolation
console.log(`My name is ${name}, I am ${age} years old and I live in ${city}`);

// String methods
console.log(name.length);
console.log(name.toUpperCase());
console.log(name.toLowerCase());
console.log(name.substring(0, 3));
console.log(name.split(''));

const goodName = new String('Aditya');
console.log(typeof goodName); // object
console.log(goodName); // [String: 'Aditya']
console.log(goodName[0]); // A
console.log(goodName.length); // 6
console.log(goodName.__proto__); // [String: '']