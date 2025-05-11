const dcHeroes = ['Batman', 'Superman', 'WonderWoman', 'Flash', 'Aquaman', 'Cyborg', 'GreenLantern'];
const marvelHeroes = ['IronMan', 'CaptainAmerica', 'Thor', 'Hulk', 'BlackWidow', 'Hawkeye', 'SpiderMan'];

// for-of
console.log('\nfor-of loop\n');

for (const hero of dcHeroes) {
    console.log(hero);
}

console.log();

for (const hero of marvelHeroes) {
    console.log(hero);
}

// for-in
console.log('\n\nfor-in loop\n');

const dcHero = {
    name: 'Batman',
    alias: 'Dark Knight',
    city: 'Gotham',
    power: 'Intelligence'
};

for (const key in dcHero) {
    if (Object.hasOwnProperty.call(dcHero, key)) {
        const element = dcHero[key];
        console.log(`${key}: ${element}`);
    }
}

const map = new Map();
map.set('IN', 'India');
map.set('US', 'United States');
map.set('UK', 'United Kingdom');
map.set('NZ', 'New Zealand');
map.set('SA', 'South Africa');
map.set('FR', 'France');

console.log()

// console.log(map);

for (const [key, value] of map) {
    console.log(`${key}: ${value}`);
}

const myObj = {
    name: 'Aditya',
    age: 25,
    city: 'Mumbai',
    country: 'India'
};

for (const key in myObj) {
    console.log(`${key}: ${myObj[key]}`);
}
