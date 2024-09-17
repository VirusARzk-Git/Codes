const pii = Math.PI;
console.log(pii);

const p = Object.getOwnPropertyDescriptor(Math, 'PI');
console.log(p);


const chai = {
    name: 'Adrak Chai',
    price: 40,
    isAvailable: true,

    orderChai: function () {
        console.log('Ordering Chai');
    }
}

console.log(chai);
const pp = Object.getOwnPropertyDescriptor(chai, 'price');
console.log(pp);

Object.defineProperty(chai, 'price', {
    writable: false,
    enumerable: false,
    // configurable: false
});
const ppp = Object.getOwnPropertyDescriptor(chai, 'price');
console.log(ppp);

for (let [key, value] of Object.entries(chai)) {
    if (typeof value !== 'function')
        console.log(`${key} : ${value}`)
}