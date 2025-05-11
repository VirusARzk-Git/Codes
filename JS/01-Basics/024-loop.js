// for

for (let i = 0; i < 10; i += 2) {
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

let j = 1;
do {
    console.log(j);
    j++;
}
while (j < 10);
