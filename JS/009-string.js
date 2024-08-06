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

const goodName = new String('Aaditya');
console.log(typeof goodName); // object
console.log(goodName); // [String: 'Aaditya']
console.log(goodName[0]); // A
console.log(goodName.length); // 7
console.log(goodName.__proto__); // [String: '']

console.log(goodName.charAt(0)); // A
console.log(goodName.charCodeAt(0)); // 65
console.log(goodName.concat(' Raj')); // Aditya Raj
console.log(goodName.includes('A')); // true
console.log(goodName.indexOf('a')); // 1
console.log(goodName.lastIndexOf('a')); // 5

const newString = goodName.substr(1, 3);
console.log(newString); // adi

const newString2 = goodName.slice(-5, 6);
console.log(newString2); // dity

const newString3 = new String("  Aaditya  ");
console.log(newString3); // [String: '  Aaditya  ']
console.log(newString3.trim()); // Aaditya

const url = 'https://virusarzk.com/virus%20arzk';
console.log(url.replace('%20', '-')); // https://virusarzk.com/virus arzk
