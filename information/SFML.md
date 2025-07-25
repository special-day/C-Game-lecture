# SFML

- 쉽고 빠른 multimedia library
- Multi-platform, multi-language
- OpenGL 기반

# ImGui

- Immediate mode GUI
- 커스터마이징이 가능하지만, 예쁘진 않음
- 직접적으로 메모리의 변수를 수정한다. (callback function 아님)
- Game loop structure에 유리하다.
- 학습과 이용이 쉽다!

## Game Loops

```
// display initial GUI screen

while(true)
{
    processInput(); // process user input if any exists
    update();       // update internal game simulation
    render();       // render current game screen
}
```

## Widgets

```
ImGui::Checkbox(“Draw Shape”, &shape.draw);

ImGui::SliderInt(“SomeInt”, &intVariable, min, max);
ImGui::SliderFloat(“SomeInt”, &intVariable, min, max);

Float v[2] = { 0.0 , 0.0 };
ImGui::SliderFloat2(“Velocity”, v, min, max);

Float shapeColor[3] = { 0.0f, 0.0f, 0.0f};
ImGui::ColorEdit3(“Color”, shapeColor);

Char buffer[255];
ImGui::InputText(“Default”, buffer, 255);

If (ImGui::Button(“Button Text”))
{
	// this happens when button is pressed
}
ImGui::SameLine();
If (ImGui::Button(“Button Two”))
{
	// this will be on the same line
}

```

## Tabs

```
If (ImGui::BeginTabBar(“MyTabBar”))
{
	If (ImGui::BeginTabItem(“Avocado”))
	{
		ImGui::Text(“This is the Avocado tab!”);
		ImGui::EndTabItem();}
	}
	If (ImGui::BeginTabItem(“Broccoli”))
	{
		ImGui::Text(“This is the Broccoli tab!”);
		ImGui::EndTabItem();
	}
	ImGui::EndTabBar();
}
```

## Combo Box

```
// by default, combo uses raw string arrays
Const char* items[] = { “AAAA”, “BBBB”, ”CCCC”, “DDDD” };
Static int item_index = 0;
ImGui::Combo(“Combo”, &item_index, items, IM_ARRAYSIZE(items));

// you may find it easier to work with vectors
Std::vector<const char*> items;
For (auto& s : shapes) { items.push_back(s.nameString.c_str()); }
Int item_index = 0;
ImGui::Combo(“Shape”, &item_index, items.data(), (int)items.size());
```

## ImGui Naming

```
// ImGui elements need to be given unique names, or the last
// one will override the behavior of any other of the same name

If (ImGui::Button(“Delete”)) { deleteThingOne(); }
If (ImGui::Button(“Delete”)) { deleteThingTwo(); }

// Can fix this by adding ## to name, which will not display

If (ImGui::Button(“Delete##D1”)) { deleteThingOne(); }
If (ImGui::Button(“Delete##D2”)) { deleteThingTwo(); }
```
