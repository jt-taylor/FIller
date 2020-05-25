# Filler
A project in which you create a `player` to decide the coordinates of where to place a game piece
* There are a lot of issues with the supplied (by 42, at least at the time this is written) ruby file that handles the game logic for this , which make this project not that interesting
* mostly that on the 100 by 100 maps the ruby program will hang forever , and that you are not guranteed to get a playable piece every round
 
This solution decides the closest corner to the opponent's starting piece and tries to place the pieces towards that corner ,
there are more interesting solutions that will produce better results like implementing a heatmap but because the ruby program has so many issues i don't think it's worth it to fix this
