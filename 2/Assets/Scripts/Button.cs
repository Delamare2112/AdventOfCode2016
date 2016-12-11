using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Button : MonoBehaviour
{
	static public Dictionary<char, Button> Buttons = new Dictionary<char, Button>();

	TextMesh text;

	void Awake()
	{
		text = GetComponentInChildren<TextMesh> ();
		Buttons.Add (text.text[0], this);
	}

	void OnCollisionEnter(Collision other)
	{
		LevelManager.instance.passCodeText.text += text.text;	
	}
}
