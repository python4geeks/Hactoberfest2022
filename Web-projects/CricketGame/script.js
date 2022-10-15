

let inds = document.querySelector('#indScore');
let paks = document.querySelector('#pakScore');
let indw = document.querySelector('#indWic');
let pakw = document.querySelector('#pakWic');

let one = document.querySelector('#one');
let two = document.querySelector('#two');
let three = document.querySelector('#three');
let four = document.querySelector('#four');
let six = document.querySelector('#six');
let out = document.querySelector('#out');
let dot = document.querySelector('#dot');
let wic = document.querySelector('#wic');
//alert(inds.textContent)
let b2 = 30;
let startM = document.querySelector('.start');
let disp = document.querySelector('.anim')
let winner = document.querySelector('.winner')
startM.addEventListener('click', play);

function play() {
    if (startM.innerText == "Start Match") {
        document.querySelector('#status').textContent = 'India is Batting';
        document.querySelector('#balls').textContent = b2;
        document.querySelector('#text').textContent = ' Balls Left';
        startM.innerText = "Reset";
        game();
    }
    else if (startM.innerText == "Reset") {
        location.reload();
    }
}

function updateScore(s) {
    if (document.querySelector('#status').textContent == 'India is Batting' && startM.innerText == "Reset") {
        if (s > -1) {
            let a = Number(inds.textContent);
            a = a + s;
            inds.textContent = a;
            let balls = Number(document.querySelector('#balls').textContent);
            balls = balls - 1;
            if (balls >= 2)
                document.querySelector('#balls').textContent = balls;
            else if (balls == 1) {
                document.querySelector('#balls').textContent = balls;
                document.querySelector('#text').textContent = ' Ball Left';
            }
            else {
                play2();
            }
        }
        else {
            let a = (-1) * Number(indw.textContent);
            a = a + s;
            if (a != -10) {
                indw.textContent = (-1) * a;
                let balls = Number(document.querySelector('#balls').textContent);
                balls = balls - 1;
                if (balls >= 2)
                    document.querySelector('#balls').textContent = balls;
                else if (balls == 1) {
                    document.querySelector('#balls').textContent = balls;
                    document.querySelector('#text').textContent = ' Ball Left';
                }
                else {
                    play2();
                }
            }
            else {
                indw.textContent = (-1) * a;
                play2();
            }
        }
    }
}

function game() {
    if (startM.innerText == "Reset") {
        one.addEventListener('click', function () {
            disp.innerHTML = '<img src="logos/logoAsset 3mdpi.png" class = "runnerR1"><img src="logos/logoAsset 4mdpi.png" class = "runnerL1">';
            updateScore(1)
        })
        two.addEventListener('click', function () {
            disp.innerHTML = '<img src="logos/logoAsset 3mdpi.png" class = "runnerR2"><img src="logos/logoAsset 4mdpi.png" class = "runnerL2">';
            updateScore(2)
        })
        three.addEventListener('click', function () {
            disp.innerHTML = '<img src="logos/logoAsset 3mdpi.png" class = "runnerR3"><img src="logos/logoAsset 4mdpi.png" class = "runnerL3">';
            updateScore(3)
        })
        four.addEventListener('click', function () {
            disp.innerHTML = '<img src="logos/logoAsset 5mdpi.png" class="shot4"><img src="logos/logoAsset 4mdpi.png" class = "runnerL">';
            updateScore(4)
        })
        six.addEventListener('click', function () {
            disp.innerHTML = '<img src="logos/logoAsset 5mdpi.png" class="shot6"><img src="logos/logoAsset 4mdpi.png" class = "runnerL">';
            updateScore(6)
        })
        dot.addEventListener('click', function () {
            disp.innerHTML = '<img src="logos/logoAsset 6mdpi.png" class="dotBall"><img src="logos/logoAsset 4mdpi.png" class = "runnerL0">';
            updateScore(0)
        })
        wic.addEventListener('click', function () {
            disp.innerHTML = '<img src="logos/logoAsset 6mdpi.png"><img src="logos/logoAsset 7mdpi.png" class="out"><img src="logos/logoAsset 4mdpi.png" class="runnerL0">';
            updateScore(-1)
        })
    }
    else
        play();
}

function play2() {
    document.querySelector('#status').textContent = 'Pakistan is Batting';
    document.querySelector('#balls').textContent = b2;
    document.querySelector('#text').textContent = ' Balls Left';
    game2();
}

function updateScore2(s) {
    if (document.querySelector('#status').textContent == 'Pakistan is Batting' && startM.innerText == "Reset") {
        if (s > -1) {
            let a = Number(paks.textContent);
            let b = Number(inds.textContent);
            a = a + s;
            paks.textContent = a;
            let balls = Number(document.querySelector('#balls').textContent);
            balls = balls - 1;
            if (balls > 0 && a <= b) {
                if (balls >= 2)
                    document.querySelector('#balls').textContent = balls;
                else if (balls == 1) {
                    document.querySelector('#balls').textContent = balls;
                    document.querySelector('#text').textContent = ' Ball Left';
                }
            }
            else {
                if (balls == 0 && a < b) {
                    winner.innerHTML = '<img src="indiawon.png" id="indwon">'
                    document.querySelector('#balls').textContent = 'Match';
                    document.querySelector('#text').textContent = ' is Over';
                    document.querySelector('#status').textContent = 'India Won';
                }
                else if (balls == 0 && a == b) {
                    winner.innerHTML = '<img src="tiematch.png" id="tie">'
                    document.querySelector('#balls').textContent = 'Match';
                    document.querySelector('#text').textContent = ' is Over';
                    document.querySelector('#status').textContent = 'Tie Match';
                }
                else {
                    winner.innerHTML = '<img src="pakistanwon.png" id="pakwon">'
                    document.querySelector('#balls').textContent = 'Match';
                    document.querySelector('#text').textContent = ' is Over';
                    document.querySelector('#status').textContent = 'Pakistan Won';
                }
                
            }
        }
        else {
            let a = (-1) * Number(pakw.textContent);
            a = a + s;
            if (a != -10) {
                pakw.textContent = (-1) * a;
                let balls = Number(document.querySelector('#balls').textContent);
                balls = balls - 1;
                if (balls >= 2)
                    document.querySelector('#balls').textContent = balls;
                    else if (balls == 1) {
                        document.querySelector('#balls').textContent = balls;
                        document.querySelector('#text').textContent = ' Ball Left';
                    }
                }
                else {
                    pakw.textContent = (-1) * a;
                let a1 = Number(paks.textContent);
                let b1 = Number(inds.textContent);
                if (a1 < b1) {
                    winner.innerHTML = '<img src="indiawon.png" id="indwon">'
                    document.querySelector('#balls').textContent = 'Match';
                    document.querySelector('#text').textContent = ' is Over';
                    document.querySelector('#status').textContent = 'India Won';

                }
                else if (a1 == b1) {
                    winner.innerHTML = '<img src="tiematch.png" id="tie">'
                    document.querySelector('#balls').textContent = 'Match';
                    document.querySelector('#text').textContent = ' is Over';
                    document.querySelector('#status').textContent = 'Tie Match';
                }
            }
        }
    }
    
}

function game2() {
    one.addEventListener('click', function () {
        updateScore2(1)
    })
    two.addEventListener('click', function () {
        updateScore2(2)
    })
    three.addEventListener('click', function () {
        updateScore2(3)
    })
    four.addEventListener('click', function () {
        updateScore2(4)
    })
    six.addEventListener('click', function () {
        updateScore2(6)
    })
    dot.addEventListener('click', function () {
        updateScore2(0)
    })
    wic.addEventListener('click', function () {
        updateScore2(-1)
    })
}

