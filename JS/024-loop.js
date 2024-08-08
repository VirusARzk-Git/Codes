// for

for (let i = 0; i < 10; i++) {
    const element = i;
    console.log(element);
}

const dcHeroes = ['Batman', 'Superman', 'WonderWoman', 'Flash', 'Aquaman', 'Cyborg', 'GreenLantern'];
for (let i = 0; i < dcHeroes.length; i++) {
    const element = dcHeroes[i];
    console.log(element);
}

const marvelHeroes = ['IronMan', 'CaptainAmerica', 'Thor', 'Hulk', 'BlackWidow', 'Hawkeye', 'SpiderMan'];
for (let i = 0; i < marvelHeroes.length; i++) {
    const element = marvelHeroes[i];
    if (element === 'Hulk') {
        console.log('Hulk is a Marvel hero');
        break;
    }
}

// print non-divisors of 3
for (let i = 1; i < 8; i++) {
    if (i % 3 === 0)
        continue;
    console.log(i);
}

// while

let i = 0;
while (i < 10) {
    console.log(i);
    i++;
}

// do-while

let j = 0;
do {
    console.log(j);
    j++;
}
while (j < 10);

// for-of

for (const hero of dcHeroes) {
    console.log(hero);
}

for (const hero of marvelHeroes) {
    console.log(hero);
}

// for-in

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
