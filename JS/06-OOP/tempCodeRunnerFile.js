const pii = Math.PI;
console.log(pii);

const p = Object.getOwnPropertyDescriptor(Math, 'PI');
console.log(p);


const chai = {
    name: 'Adrak Chai',
    price: 40,
    isAvailable: true
}

console.log(chai);
const pp = Object.getOwnPropertyDescriptor(chai);
console.log(pp);
