using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LevelManager : MonoBehaviour {
	public static LevelManager instance;

	public TextMesh passCodeText;
	public UnityEngine.UI.Text Status;

	void Awake()
	{
		instance = this;
		passCodeText.text = "";
	}
}
