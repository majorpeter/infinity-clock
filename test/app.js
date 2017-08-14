var canvas;
var frame = 0;
var interval;

function fillCircle(x, y, r, color) {
   var ctx = canvas.getContext('2d');
   ctx.beginPath();
   ctx.arc(x, y, r, 0, 2 * Math.PI);
   ctx.fillStyle = color;
   ctx.fill();
}

function drawClockFace(led_data) {
   var xy = 300;
   var radius = 280;
   for (var i = 0; i < 60; i++) {
      var angle = (-Math.PI / 2) + (i * Math.PI / 30);
      fillCircle(xy + Math.cos(angle) * radius, xy + Math.sin(angle) * radius, 9, led_data[i]);
   }
}

function onLoad() {
   // Get the canvas element using the DOM
   canvas = document.getElementById('mycanvas');

   // Make sure we don't execute when canvas isn't supported
   if (canvas.getContext){
      interval = setInterval(function() {
         if (json_data[frame]) {
            document.getElementById('frameNumber').textContent = frame;
            drawClockFace(json_data[frame])
         } else {
            alert('Done');
            clearInterval(interval);
            return;
         }
         frame = frame + 1;
      }, 16);
   }
   else {
      alert('You need Safari or Firefox 1.5+ to see this demo.');
   }
}

function stop() {
   clearInterval(interval);
}