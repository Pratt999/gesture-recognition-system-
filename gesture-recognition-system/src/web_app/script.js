const gestureEl = document.getElementById("gesture");
const confidenceEl = document.getElementById("confidence");
const statusEl = document.getElementById("status");

// Connect to WebSocket server
const socket = new WebSocket("ws://localhost:5000/ws");

socket.onopen = () => {
  statusEl.textContent = "Connected";
  statusEl.style.color = "green";
};

socket.onmessage = (event) => {
  const data = JSON.parse(event.data);
  gestureEl.textContent = data.gesture;
  confidenceEl.textContent = (data.confidence * 100).toFixed(1) + "%";
};

socket.onerror = (error) => {
  console.error("WebSocket error:", error);
};

socket.onclose = () => {
  statusEl.textContent = "Disconnected";
  statusEl.style.color = "red";
};
