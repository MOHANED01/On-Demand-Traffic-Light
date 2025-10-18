<h1> On-Demand Traffic Light System (ATmega32)</h1>
<p>
  A smart <strong>On-Demand Traffic Light System</strong> built on the <strong>ATmega32</strong> microcontroller.  
  This embedded system allows pedestrians to safely cross the road by requesting traffic light changes via a push-button, 
  while ensuring smooth and safe transitions for vehicle traffic using <strong>timers</strong> and <strong>interrupts</strong>.
</p>

<hr />

<h2>📌 Project Overview</h2>
<p>
  Developed as part of the <strong>Embedded Systems Professional Nanodegree (EGYFWD)</strong>, this project demonstrates 
  embedded system design using a <strong>layered architecture</strong>, and modular driver development.  
  The system models a typical traffic intersection with vehicle and pedestrian lights that operate both automatically and on-demand.
</p>

<h3>📌 Objectives</h3>
<ul>
  <li>Implement a pedestrian-controlled traffic light system using <strong>ATmega32</strong>.</li>
  <li>Design an interrupt-driven pedestrian button interface (INT0).</li>
  <li>Use <strong>Timer0</strong> for accurate non-blocking delays.</li>
  <li>Develop reusable, well-structured code following <strong>MCAL → HAL → APP</strong> layers.</li>
</ul>

<hr />

<h2>📌 System Architecture</h2>
<pre><code>          ┌──────────────────────────┐
          │       ATmega32 MCU       │
          │ ──────────────────────── │
          │  GPIO - LED interface    │
          │  Timer0 - delay control  │
          │  EXTI0 - button input    │
          └──────────────────────────┘
                   ▲          ▲
                   │          │
             Pedestrian   Vehicle LEDs
                Button   (Green, Yellow, Red)
</code></pre>

<hr />

<h2>📌 Features</h2>
<ul>
  <li> control using <strong>timer interrupts</strong> and <strong>EXTI</strong>.</li>
  <li>Safe pedestrian crossings triggered by a button press.</li>
  <li>Automatic light sequencing in normal operation.</li>
  <li>Modular and reusable codebase with <strong>APP</strong>, <strong>HAL</strong> and <strong>MCAL</strong> layers.</li>
  <li>Non-blocking delays for smooth state transitions.</li>
</ul>

<hr />


<h2>📌 Technical Specifications</h2>
<table>
  <thead>
    <tr><th>Component</th><th>Details</th></tr>
  </thead>
  <tbody>
    <tr><td><strong>Microcontroller</strong></td><td>ATmega32</td></tr>
    <tr><td><strong>Clock Frequency</strong></td><td>16 MHz</td></tr>
    <tr><td><strong>Programming Language</strong></td><td>Embedded C</td></tr>
    <tr><td><strong>Architecture</strong></td><td>Layered (MCAL → HAL → APP)</td></tr>
    <tr><td><strong>Control Mechanism</strong></td><td>Timer-based state machine with EXTI0 interrupt</td></tr>
    <tr><td><strong>Toolchain</strong></td><td>Eclipse</td></tr>
    <tr><td><strong>Simulation Tool</strong></td><td>Proteus</td></tr>
  </tbody>
</table>

<hr />

<h2>📌 How It Works</h2>
<ol>
  <li><strong>Normal Mode</strong>
    <ul>
      <li>Vehicle lights cycle automatically: Green → Yellow → Red → Green.</li>
      <li>Pedestrian light remains Red during this cycle.</li>
    </ul>
  </li>
  <li><strong>Pedestrian Request Mode</strong>
    <ul>
      <li>Pressing the button triggers an <strong>External Interrupt (INT0)</strong>.</li>
      <li>The MCU completes the current cycle safely before stopping cars.</li>
      <li>Pedestrian light turns Green, allowing safe crossing.</li>
      <li>After delay, system returns to normal traffic operation.</li>
    </ul>
  </li>
  <li><strong>Safety Mechanism:</strong> The system ensures no conflicting lights are ON simultaneously and transitions are smooth.</li>
</ol>

<hr />

<h2>📌 Testing &amp; Validation</h2>
<ul>
  <li>Tested in <strong>Proteus</strong> simulation environment.</li>
  <li>Verified interrupt response.
  <li>Observed correct LED sequencing and pedestrian behavior.</li>
</ul>

<hr />

<h2>📌 Build &amp; Flash Instructions</h2>

<h3>Requirements</h3>
<ul>
  <li>Eclipse</li>
  <li>Proteus (optional for simulation)</li>
</ul>

<h3>Steps</h3>
<ol>
  <li>Open the project in Eclipse.</li>
  <li>Build the project to generate the <code>.hex</code> file.</li>
  <li>Flash firmware to ATmega32 using proteus.</li>

</ol>

<hr />

<h2>📌 Example Operation</h2>
<pre><code>[Normal Mode]
Car: Green → Yellow → Red
Pedestrian: Red → Red → Green

[Button Press]
→ Interrupt Triggered
Car: Safely transitions to Red
Pedestrian: Green (cross)
After delay → Resumes Normal Mode
</code></pre>

<hr />

<h2>📌 Future Enhancements</h2>
<ul>
  <li>Add <strong>buzzer alerts</strong> during pedestrian crossing.</li>
  <li>Introduce <strong>adaptive timing</strong> using traffic sensors.</li>
  <li>Implement <strong>night mode</strong> (blinking yellow).</li>
  <li>Integrate <strong>LCD or Bluetooth display</strong> for status monitoring.</li>
</ul>

<hr />

