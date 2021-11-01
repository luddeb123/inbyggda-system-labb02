# inbyggda-system-labb02
## Description
> Labben går i stora drag ut på att använda timer/compare-enheten på Arduinon för att periodiskt blinka en LED, och sedan använda pulsbreddsmodulering för att variera ljusstyrkan på LEDen. Syftet med det är i första hand att bekanta dig med timers och dess olika användningsområden, samt konfigurering av något mer komplexa periferienheter.


##### DELUPPGIFT 1: BLINKA LED
Använd samma LEDar och resistorer som i labb 1
1. Koppla in LED och lämplig resistor till pinne 8 på Arduinons expansionsport med hjälp av kopplingsdäck och kablar. Minns från labb 1 att det motvarar PORTB0, och konfigurera upp den som utgång (alternativt valfri led på din egentillverkade, handgjorda, lokalproducerade sköld!).

2. Konfigurera upp timer0 mha kap 19 i databladet:
    * CTC-mod (Clear Timer on Compare Match mode)
    * Prescaler = 1024
    * Använd den informationen och databladet för att hitta ett output compare-värde som motsvarar en periodtid på 10 millisekunder. Minns att CPU-klockan är ställd till 16 MHz. Ta med uträkningen och värdet i git-committen.

3. Skapa en oändlig loop i `main()`. I den, vänta på att räknaren når/matchar output comparevärdet (övervaka matchflaggan), och när så sker:
    * Rensa flaggan
    * Inkrementera en räknarvariabel, och när denna når 10; nollställ den och toggla LEDen. Detta för att förenkla, ögat ser inte blinkningarna i 100 Hz, så vi delar ner frekvensen till 10 Hz. Skriv och testa gärna den här delen innan du kopplar in timer-koden.

4. Städa upp din kod och skapa en git-commit med ovanstående
