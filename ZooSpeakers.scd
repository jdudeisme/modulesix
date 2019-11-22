z = Buffer.read(s, "SavannahShort.wav".resolveRelative);
z.play;

j = 1;
k = 0.2;

a = Bus.control(s, 2); //amplitude control bus
a.set(k);

b = Bus.control(s, 2); //playback rate control bus
b.set(j);



(
x = SynthDef("Zoo",{ | out = 0, amp = 0.5, bufnum |
    Out.ar(out,
		PlayBuf.ar(2, bufnum, b.kr(1), loop: 1) * a.kr(1);
    )
}).play(s,[\bufnum, z]);
)


j = j + 0.25;  //increase speed  -- coffee cabinet
j = j - 0.25;  // decrease speed -- fridge handle
j = j * -1;     //reverse playback -- microwave


SerialPort.listDevices;
p = ArduinoSMS("/dev/tty.SLAB_USBtoUART", 115200);


(
p.action = {|... msg|

	msg.postln;

	if (msg[0] == "IN"){ if (k < 4){ k = k + 0.2; }; a.set(k);};
	if (msg[1] == "On"){ j = j * -1; b.set(j); };
	if (msg[1] == "Off"){ ("Nope").postln;};
	if (msg[0] == "Microwave, Off"){ ("Nope").postln; };
	if (msg[0] == "Closed"){ j = j + 0.25; b.set(j);};
	if (msg[0] > 16 ) { j = j - 0.25; b.set(j); };
	j.postln;
}
)

p.close;

j; //for keeping track of values
k;