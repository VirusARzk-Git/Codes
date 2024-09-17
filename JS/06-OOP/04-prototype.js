let myHeroes = ['Thor','Spidey']

let heroPower = {
    Thor: 'Mjolnir',
    Spidey: 'Sling',

    getSpiderPower: function() {
        console.log(`Spiderman uses ${this.Spidey}`);
    }
}

console.log(heroPower.Thor);
console.log(heroPower.Spidey);

heroPower.getSpiderPower();

Object.prototype.virus = function() {
    console.log('Virus is present in all objects');
}

heroPower.virus();
myHeroes.virus();

Array.prototype.virus2 = function() {
    console.log('Virus is present in all arrays');
}

myHeroes.virus2();
// heroPower.virus2();

String.prototype.trueLen = function(){
    return this.trim().length
}

let myName = "Aditya  "

console.log(myName.length);
console.log(myName.trueLen());



// Inheritance

const User = {
    username : 'Virus',
    email : 'virus@example.com'
}